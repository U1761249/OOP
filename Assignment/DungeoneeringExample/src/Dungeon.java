
import java.awt.Color;
import java.awt.Graphics;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class Dungeon {

    public Base base;
    private Room[][] rooms;

    public Dungeon(int sizeX, int sizeY) {
        //int x = (int) (Math.random() * sizeX);
        //int y = (int) (Math.random() * sizeY);
        //By using multiple rolls it makes it more likely to be in the middleish
        int x = (int) (Math.random() * 3) + (int) (Math.random() * 4) + (int) (Math.random() * 3);
        int y = (int) (Math.random() * 3) + (int) (Math.random() * 4) + (int) (Math.random() * 3);
        rooms = new Room[sizeX][sizeY];
        rooms[x][y] = base = new Base(x, y);
    }

    public Base getBase() {
        return base;
    }

    public Room getRoom(int x, int y) {
        if (x < 0 || y < 0 || x >= rooms.length || y >= rooms[x].length) {
            return null;
        }
        return rooms[x][y];
    }

    public Set<Room> getNeighbors(int x, int y) {
        Set<Room> neighbors = new HashSet<Room>();
        neighbors.add(getRoom(x - 1, y));
        neighbors.add(getRoom(x + 1, y));
        neighbors.add(getRoom(x, y - 1));
        neighbors.add(getRoom(x, y + 1));
        neighbors.removeIf(r -> r == null || r.isBoss);
        return neighbors;
    }

    public void draw(Graphics g) {
        Color BG = new Color(160, 145, 108);
        Color N = new Color(137, 102, 50);
        Color C = new Color(160, 120, 58);
        Color BASE = new Color(140, 135, 95);
        Color BOSS = new Color(88, 27, 18);

        g.setColor(BG);
        g.fillRect(0, 0, 500, 500);

        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[i].length; j++) {
                Room r = rooms[i][j];
                if (r == null)
                    continue;

                if (r instanceof Base) {
                    g.setColor(BASE);
                } else if (r.isBoss) {
                    g.setColor(BOSS);
                } else {
                    g.setColor(r.isCritPath ? C : N);
                }
                g.fillRect(30 + r.x * 50, 50 + r.y * 50, 40, 40);

                if (!(r instanceof Base)) {

                    int dx = r.x - r.parent.x;
                    int dy = r.y - r.parent.y;
                    int sx = dx < 0 ? 40 : -10;
                    int sy = dy < 0 ? 40 : -10;
                    int x = 10;
                    int y = 10;
                    if (dx == 0) {
                        sx = 13;
                        x = 14;
                    }
                    if (dy == 0) {
                        sy = 13;
                        y = 14;
                    }
                    g.fillRect(r.x * 50 + 30 + sx, r.y * 50 + 50 + sy, x, y);
                    if (r.lock != 0) {
                        g.setColor(Color.red);
                        g.drawString("" + rooms[i][j].lock, r.x * 50 + 28 + sx, r.y * 50 + 60 + sy);
                    }
                }
                if (rooms[i][j].key != 0) {
                    g.setColor(Color.green);
                    g.drawString("" + rooms[i][j].key, 50 + r.x * 50, 70 + r.y * 50);
                }
            }
        }
    }

    public void addRoom(int x, int y, Room room) {
        rooms[x][y] = room;
    }

    public void removeRoom(Room r) {
        r.parent.children.remove(r);
        rooms[r.x][r.y] = null;
    }

    public List<Room> getRooms() {
        List<Room> roomList = new LinkedList<Room>();
        for (int x = 0; x < rooms.length; x++) {
            for (int y = 0; y < rooms[0].length; y++) {
                if (rooms[x][y] != null) {
                    roomList.add(rooms[x][y]);
                }
            }
        }
        return roomList;
    }

    public List<Room> getShuffledRooms() {
        List<Room> roomList = getRooms();
        Collections.shuffle(roomList);
        return roomList;
    }

    public int getRoomCount() {
        int count = 0;
        for (int x = 0; x < rooms.length; x++) {
            for (int y = 0; y < rooms[0].length; y++) {
                if (rooms[x][y] != null) {
                    count++;
                }
            }
        }
        return count;
    }

    public boolean trim(Room r) {
        if (r.children.isEmpty()) {
            if (r.lock == 0 && r.key == 0) {
                return true;
            }
        } else {
            Iterator<Room> it = r.children.iterator();
            Room c;
            while (it.hasNext()) {
                c = it.next();
                if (trim(c)) {
                    it.remove();
                    removeRoom(c);
                }
            }
        }
        return false;
    }


}