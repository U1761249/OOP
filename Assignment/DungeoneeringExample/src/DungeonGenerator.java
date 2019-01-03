
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Set;
import java.util.function.Consumer;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class DungeonGenerator {

    private final static int sizeX = 8;
    private final static int sizeY = 8;
    public static final double LOCK_RATE = 0.3;
    public static int total = 0;
    public static int[] distribution1 = new int[64];
    public static int[] distribution2 = new int[64];
    public static int[] distribution3 = new int[64];
    public static int[] distribution4 = new int[64];

    private static int img;

    public static void main(String[] args) throws InterruptedException {
        List<Point> queue = new ArrayList<Point>();

        final Dungeon dungeon = new Dungeon(sizeX, sizeY);
        queue.add(new Point(dungeon.getBase().x - 1, dungeon.getBase().y));
        queue.add(new Point(dungeon.getBase().x + 1, dungeon.getBase().y));
        queue.add(new Point(dungeon.getBase().x, dungeon.getBase().y - 1));
        queue.add(new Point(dungeon.getBase().x, dungeon.getBase().y + 1));
        JFrame frame = new JFrame() {
            private static final long serialVersionUID = 1L;

            @Override
            public void paint(Graphics g) {
                //super.paint(g);
                dungeon.draw(g);
            }
        };
        frame.pack();
        frame.setSize(480, 480);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Generate full dungeon
        while (!queue.isEmpty()) {
            Point next = random(queue);
            //Ensure the edge is within the dungeon boundary and it doesn't already exist
            if (next.x < 0 || next.y < 0 || next.x >= sizeX || next.y >= sizeY || dungeon.getRoom(next.x, next.y) != null) {
                continue;
            }

            //Connect this edge to a random neighboring room
            Room parent = randomParent(dungeon, next.x, next.y);

            Room room = new Room(parent, next.x, next.y);
            dungeon.addRoom(next.x, next.y, room);

            queue.add(new Point(next.x - 1, next.y));
            queue.add(new Point(next.x + 1, next.y));
            queue.add(new Point(next.x, next.y - 1));
            queue.add(new Point(next.x, next.y + 1));
        }

        //Create gaps by removing random DE's
        int remove = (int) (Math.random() * 15);
        for (int i = 0; i < remove; i++) {
            dungeon.removeRoom(dungeon.getShuffledRooms().stream().filter(r -> r.children.isEmpty()).findFirst().get());
        }

        Room boss;
        //Choose crit
        while (true) {
            //Sets only have distinct elements so no need to worry about overlapping paths
            Set<Room> critPath = new HashSet<Room>();
            boss = dungeon.getShuffledRooms().stream().filter(r -> r.children.isEmpty()).findFirst().get();
            critPath.addAll(boss.pathToBase());
            critPath.addAll(dungeon.getShuffledRooms().get(0).pathToBase());
            critPath.addAll(dungeon.getShuffledRooms().get(0).pathToBase());
            critPath.addAll(dungeon.getShuffledRooms().get(0).pathToBase());
            if (Math.random() > 0.5) {
                critPath.addAll(random(dungeon.getRooms()).pathToBase());
            }

            System.out.println("picked " + critPath.size());

            if (critPath.size() >= 19 && critPath.size() <= 23) {
                critPath.forEach(r -> r.isCritPath = true);
                boss.isBoss = true;
                frame.repaint();
                break;
            }
        }

        //Add keys to crit, let's make some lists
        List<Integer> availableKeys = IntStream.range(1, 64).boxed().collect(Collectors.toList());
        //Shuffle the keys so it doesn't use the same ones every dungeon, for testing its nicer to have it non shuffled though
        //Collections.shuffle(availableLocks);

        Queue<Room> unplacedLocks = new LinkedList<Room>();
        List<Room> lockable = dungeon.getRooms().stream().filter(r -> !r.isBoss && r.isCritPath).collect(Collectors.toList());

        Consumer<Room> assignKey = r -> {
            r.key = availableKeys.remove(0);
            unplacedLocks.add(r);
        };

        //TODO: These 2 loops can probably be merged fairly easily
        //Crit locks
        dungeon.getRooms().stream().filter(r -> !r.isBoss && r.children.stream().noneMatch(c -> c.isCritPath) && r.isCritPath).forEach(assignKey);
        dungeon.getShuffledRooms().stream().filter(r -> !r.isBoss && r.isCritPath && r.key == 0).limit(4).forEach(assignKey);
        Collections.shuffle((List<?>) unplacedLocks);
        while (unplacedLocks.size() > 1) {
            Room next = unplacedLocks.poll();
            int key = next.key;
            List<Room> unreachable = new LinkedList<Room>();
            Queue<Room> unreachableQueue = new LinkedList<Room>();
            unreachableQueue.add(next);
            while ((next = unreachableQueue.poll()) != null) {
                unreachable.add(next);
                if (next.lock > 0) {
                    Room curr = next;
                    unreachableQueue.add(dungeon.getRooms().stream().filter(r -> r.key == curr.lock).findFirst().get());
                }
                if (next.parent != null) {
                    unreachableQueue.add(next.parent);
                }
            }
            List<Room> candidates = new LinkedList<Room>(lockable);
            candidates.removeAll(unreachable);
            if (candidates.isEmpty()) { //TODO: fix this? This can happen if the end of branches are picked early, there just wont be anything to lock!
                System.out.println("Meh. Fuck this. Discarding");
                frame.dispose();
                main(null);
                return;
            }
            Room lockRoom = random(candidates);
            lockRoom.lock = key;
            lockable.remove(lockRoom);
        }
        boss.lock = unplacedLocks.poll().key;

        //Bonus locks
        lockable = dungeon.getRooms().stream().filter(r -> !r.isBoss && !r.isCritPath).collect(Collectors.toList());
        dungeon.getShuffledRooms().stream().filter(r -> !r.isBoss && r.key == 0).limit(5 + (int)(Math.random() * 7)).forEach(assignKey);
        Collections.shuffle((List<?>) unplacedLocks);

        while (unplacedLocks.size() > 0) {
            Room next = unplacedLocks.poll();
            int key = next.key;
            List<Room> unreachable = new LinkedList<Room>();
            Queue<Room> unreachableQueue = new LinkedList<Room>();
            unreachableQueue.add(next);
            while ((next = unreachableQueue.poll()) != null) {
                unreachable.add(next);
                if (next.lock > 0) {
                    Room curr = next;
                    unreachableQueue.add(dungeon.getRooms().stream().filter(r -> r.key == curr.lock).findFirst().get());
                }
                if (next.parent != null) {
                    unreachableQueue.add(next.parent);
                }
            }
            List<Room> candidates = new LinkedList<Room>(lockable);
            candidates.removeAll(unreachable);
            if (candidates.isEmpty()) { //Pretty much impossible on bonus, just incase though
                System.out.println("Meh. Fuck this");
                frame.dispose();
                main(null);
                return;
            }
            Room lockRoom = random(candidates);
            lockRoom.lock = key;
            lockable.remove(lockRoom);
        }


        //Statistics
        total++;
        distribution1[(int) dungeon.getRooms().stream().filter(r -> r.isCritPath).count()]++;
        for (int i = 0; i < distribution1.length; i++) {
            if (distribution1[i] > 0) {
                System.out.println("crc " + i + " " + (double) distribution1[i] / (double) total * 100 + "%");
            }
        }
        distribution2[(int) dungeon.getRooms().stream().filter(r -> r.children.stream().noneMatch(c -> c.isCritPath) && r.isCritPath).count()]++;
        for (int i = 0; i < distribution2.length; i++) {
            if (distribution2[i] > 0) {
                System.out.println("cbr " + i + " " + (double) distribution2[i] / (double) total * 100 + "%");
            }
        }
        distribution3[(int) dungeon.getRooms().stream().filter(r -> r.children.isEmpty() && r.isCritPath).count()]++;
        for (int i = 0; i < distribution3.length; i++) {
            if (distribution3[i] > 0) {
                System.out.println("cde " + i + " " + (double) distribution3[i] / (double) total * 100 + "%");
            }
        }
        distribution4[dungeon.getRooms().stream().map(r -> r.depthToCrit()).sorted((r1, r2) -> r2 - r1).findFirst().get()]++;
        for (int i = 0; i < distribution4.length; i++) {
            if (distribution4[i] > 0) {
                System.out.println("bdepth " + i + " " + (double) distribution4[i] / (double) total * 100 + "%");
            }
        }
        frame.repaint();
        BufferedImage bImg = new BufferedImage(frame.getWidth(), frame.getWidth(), BufferedImage.TYPE_INT_RGB);
        Graphics2D cg = bImg.createGraphics();
        frame.paintAll(cg);
        try {
            if (ImageIO.write(bImg, "png", new File("./dungeon/" + (img++) + ".png"))) {
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Generated " + total + " dungeons.");

		/*frame.dispose();
		main(null);*/
    }

    static Room randomParent(Dungeon dungeon, int x, int y) {
        Set<Room> neighbors = new HashSet<Room>();
        neighbors.add(dungeon.getRoom(x - 1, y));
        neighbors.add(dungeon.getRoom(x + 1, y));
        neighbors.add(dungeon.getRoom(x, y - 1));
        neighbors.add(dungeon.getRoom(x, y + 1));
        neighbors.removeIf(r -> r == null || r.isBoss); //These are not valid parents
        return (Room) neighbors.toArray()[(int) (neighbors.size() * Math.random())];
    }

    static <T> T random(List<T> list) {
        return list.remove((int) (Math.random() * list.size()));
    }

}