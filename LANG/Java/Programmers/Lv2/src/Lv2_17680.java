public class Lv2_17680 {
    public static void main(String[] args) {
        Solution17680 s = new Solution17680();
        int cacheSize = 2;
        String[] cities = {"Jeju", "Pangyo", "NewYork", "newyork"};
        s.solution(cacheSize, cities);
    }
}

class Solution17680 {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        LRU lru = new LRU(cacheSize);
        for (String c : cities) {
            answer += lru.addNodes(c);
        }
        System.out.println(answer);
        return answer;
    }
    private static class Nodes {
        Nodes preNode;
        Nodes nextNode;
        String city;

        public Nodes (String city, Nodes preNode, Nodes nextNode) {
            this.preNode = preNode;
            this.nextNode = nextNode;
            this.city = city.toLowerCase();
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

        public Integer addNodes (String nodeAdd) {
            Nodes node = this.head.nextNode;
            while(!node.city.equals("")) {
                if (nodeAdd.toLowerCase().equals(node.city)) {
                    this.cacheHit(node, nodeAdd);
                    return 1;
                }
                node = node.nextNode;
            }
            this.cacheMiss(nodeAdd);
            return 5;
        }

        public void cacheHit(Nodes node, String nodeAdd) {
            this.removeNode(node);
            this.addFront(nodeAdd);
        }
        public void cacheMiss(String nodeAdd) {
            this.addFront(nodeAdd);
            if (this.totalLen() > this.size) {
                this.removeTail();
            }
        }
        public void removeTail() {
            this.tail.preNode.preNode.nextNode = this.tail;
            this.tail.preNode = this.tail.preNode.preNode;
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
            node.nextNode.preNode = node.preNode;
            node.preNode.nextNode = node.nextNode;
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