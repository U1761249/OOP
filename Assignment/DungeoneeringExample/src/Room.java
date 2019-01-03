
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;


public class Room {

    int x;
    int y;
    int key;
    int lock; //This should be changed to also allow skills/guardian
    boolean isCritPath;
    boolean isBoss;

    /**
     * The parent room is the room that is on the path to the base
     */
    public Room parent;

    /**
     * All the connected rooms leading away from the base
     */
    public List<Room> children;

    public Room(Room parent, int x, int y) {
        this.children = new ArrayList<Room>();
        this.parent = parent;
        if (parent != null) //Base doesn't have a parent
            parent.children.add(this);
        this.x = x;
        this.y = y;
    }

    public int depth() {
        int n = 0;
        Room p = parent;
        while(p != null) {
            n++;
            p = p.parent;
        }
        return n;
    }

    public int depthToCrit() {
        int n = 0;
        Room p = this;
        while(!p.isCritPath) {
            n++;
            p = p.parent;
        }
        return n;
    }

    public List<Room> pathToBase() {
        List<Room> path = new LinkedList<Room>();
        Room p = this;
        while(p != null) {
            path.add(p);
            p = p.parent;
        }
        return path;
    }

}