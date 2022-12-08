import java.util.ArrayList;

public class Lv2_17680 {
    public static void main(String[] args) {
        Solution17680 s = new Solution17680();

    }
}

class Solution17680 {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;



        return answer;
    }
    private static class Nodes {
        Nodes preNode;
        Nodes nextNode;
        String city;

        public Nodes (String city, Nodes preNode, Nodes nextNode) {
            this.preNode = preNode;
            this.nextNode = nextNode;
            this.city = city;
        }
    }
    private static class LRU {
        int size;
        Nodes head;
        Nodes tail;

        public LRU(int size) {
            this.head = new Nodes("", null, null);
            this.tail = new Nodes("", null, null);
            this.size = size;
            head.nextNode = tail;
            tail.preNode = head;
        }

        public void addNodes (String nodeAdd) {
            Nodes node = this.head.nextNode;

            while(!node.city.equals("")) {
                if (nodeAdd.equals(node.city)) {
                    this.cacheHit(node, nodeAdd);
                    return;
                }
                node = node.nextNode;
            }
            this.cacheMiss(nodeAdd);
        }

        public Integer cacheHit(Nodes node, String nodeAdd) {
            this.removeNode(node);
            this.addFront(nodeAdd);
            return 5;
        }
        public void cacheMiss(String nodeAdd) {
            this.addFront(nodeAdd);
            if (this.totalLen() > this.size) {
                this.removeTail();
            }

        }
        public removeTail() {
            
        }
        public Integer totalLen() {
            int length = 0;
            Nodes node = this.head.nextNode;
            while (!node.city.equals("")) {
                length ++;
                node = node.nextNode;
            }
            return length;
        }
        public void removeNode(Nodes node) {

        }
        public void addFront(String nodeAdd) {
            Nodes newNode = new Nodes(nodeAdd, null, null);
            this.head.nextNode.preNode = newNode;
            newNode.nextNode = this.head.nextNode;
            this.head.nextNode = newNode;
            newNode.preNode = this.head;
        }
    }
}