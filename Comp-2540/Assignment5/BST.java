public class BST<T> {
    private Node<T> root;

    public BST() {
        root = null;
    }

    public void insert(int key, T value) {
        root = insertAtExternal(key, value, root);
    }

    private Node<T> insertAtExternal(int key, T value, Node<T> node) {
        if (node == null) {
            node = new Node<T>(key, value);
        } else if (node.getKey() > key) {
            node.setLeft(insertAtExternal(key, value, node.getLeft()));
        } else if (node.getKey() < key) {
            node.setRight(insertAtExternal(key, value, node.getRight()));
        }

        return node;
    }

    public T search(int key) {
        Node<T> node = searchNode(key, root);
        return node != null ? node.getValue() : null;
    }

    private Node<T> searchNode(int key, Node<T> node) {
        if (node == null || node.getKey() == key) {
            return node;
        } else if (node.getKey() > key) {
            return searchNode(key, node.getLeft());
        } else {
            return searchNode(key, node.getRight());
        }
    }

    public void remove(int key) {
        root = removeExternal(key, root);
    }

    private Node<T> removeExternal(int key, Node<T> node) {
        if (root.getLeft() == null && root.getRight() == null && root.getKey() == key) {
            root = null;
        }

        if (node == null) {
            return null;
        } 
        
        if (node.getKey() > key) {
            node.setLeft(removeExternal(key, node.getLeft()));
        } else if (node.getKey() < key) {
            node.setRight(removeExternal(key, node.getRight()));
        } else {
            if (node.getLeft() == null && node.getRight() == null) {
                return null;
            } else if (node.getLeft() == null) {
                return node.getRight();
            } else if (node.getRight() == null) {
                return node.getLeft();
            } else {
                Node<T> previousNode = findMin(node.getRight());
                node.setKey(previousNode.getKey());
                node.setValue(previousNode.getValue());
                node.setRight(removeExternal(previousNode.getKey(), node.getRight()));
            }
        }
        return node;
    }

    private Node<T> findMin(Node<T> node) {
        while (node.getLeft() != null) {
            node = node.getLeft();
        }
        return node;
    }

    public void printTree(BST<T> tree) {
        int i = 1;
        while (root != null) {
            System.out.println(tree.search(i));
            i++;
        }
    }

    public static void main(String[] args) {
        BST<Integer> bst = new BST<Integer>();
        bst.insert(1, 13);
        bst.insert(2, 20);
        bst.insert(3, 50);
        bst.insert(4, 99);
        bst.insert(5, 115);
        bst.insert(6, 120);
        bst.insert(7, 159);
        bst.insert(8, 160);
        bst.insert(9, 170);
        bst.insert(10, 171);
        bst.insert(11, 172);
        bst.insert(12, 390);

        bst.remove(5);
        bst.insert(5, 117);
        bst.remove(1);
        bst.insert(1, 8);

        for (int i = 1; i <= 12; i++) {
            System.out.println(bst.search(i));
        }
        
        // for (int i = 12; i >= 1; i--) {
        //     System.out.println(bst.search(i));
        // }


    }
}
