# 🌳 Binary Trees & Binary Search Trees (BST)

A comprehensive collection of Binary Tree and Binary Search Tree implementations and algorithms in C++.

---

## 📁 Files Overview

| File | Description | Key Concepts |
|------|-------------|--------------|
| `BST.cpp` | Binary Search Tree implementation with insertion, deletion, and search operations | BST properties, recursive operations |
| `binary_tree_traversals.cpp` | Implementation of tree traversal techniques | Inorder, Preorder, Postorder, Level-order |
| `Balanced_BT_Checker.cpp` | Algorithm to check if a binary tree is balanced | Height calculation, balance factor |
| `check_balancedBT.cpp` | Alternative approach to check tree balance | Recursive height checking |
| `childrenTreeSum.cpp` | Validates if parent node equals sum of children | Tree property verification |
| `diameter_bt.cpp` | Calculates the diameter (longest path) of a binary tree | Path calculation, height tracking |
| `inorder_Preorder_to_postorder.cpp` | Constructs tree and converts between traversal orders | Tree reconstruction, traversal conversion |
| `maxdepth.cpp` | Finds the maximum depth/height of a binary tree | Recursive depth calculation |

---

## 🎯 Topics Covered

### Binary Tree Fundamentals
- Tree structure and node representation
- Parent-child relationships
- Leaf and internal nodes

### Tree Traversals
- **Inorder** (Left → Root → Right)
- **Preorder** (Root → Left → Right)
- **Postorder** (Left → Right → Root)
- **Level-order** (Breadth-First)

### Binary Search Tree (BST)
- BST property: Left < Root < Right
- Insertion and deletion operations
- Search operations (O(log n) average case)

### Tree Properties
- **Height/Depth**: Maximum distance from root to leaf
- **Diameter**: Longest path between any two nodes
- **Balanced Tree**: Height difference ≤ 1 for all nodes
- **Children Sum**: Parent value equals sum of children

---

## 🚀 Quick Start

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- Basic understanding of recursion and pointers

### Compilation
```bash
# Compile any file
g++ -o output filename.cpp

# Example
g++ -o bst BST.cpp

# Run
./output
```

---

## 📚 Learning Path

**Recommended order for beginners:**

1. **Start Here** → `binary_tree_traversals.cpp`
   - Understand how to traverse trees
   - Learn the three main traversal types

2. **Tree Properties** → `maxdepth.cpp`
   - Calculate tree height
   - Understand recursive thinking

3. **BST Basics** → `BST.cpp`
   - Learn BST insertion and search
   - Understand BST properties

4. **Advanced Concepts** → `diameter_bt.cpp`, `Balanced_BT_Checker.cpp`
   - Complex tree algorithms
   - Multiple property checking

5. **Tree Construction** → `inorder_Preorder_to_postorder.cpp`
   - Build trees from traversals
   - Convert between formats

---

## 💡 Key Algorithms Explained

### Checking if Tree is Balanced
```
A tree is balanced if:
- Left subtree is balanced
- Right subtree is balanced
- |height(left) - height(right)| ≤ 1
```

### Calculating Diameter
```
Diameter = max of:
- Diameter of left subtree
- Diameter of right subtree
- Longest path through root (left_height + right_height)
```

### Tree Reconstruction
```
Given Inorder + Preorder/Postorder:
- Can uniquely reconstruct the binary tree
- Inorder gives left/right split
- Pre/Postorder gives root position
```

---

## 🔍 Common Operations Complexity

| Operation | Binary Tree | BST (Balanced) | BST (Skewed) |
|-----------|-------------|----------------|--------------|
| Search | O(n) | O(log n) | O(n) |
| Insert | O(n) | O(log n) | O(n) |
| Delete | O(n) | O(log n) | O(n) |
| Traversal | O(n) | O(n) | O(n) |
| Height | O(n) | O(n) | O(n) |

---

## 🛠️ Common Use Cases

- **BST**: Implementing dictionaries, priority queues, database indexing
- **Balanced Trees**: Ensuring O(log n) operations (AVL, Red-Black trees)
- **Tree Traversals**: Expression evaluation, serialization, file systems
- **Diameter**: Network design, finding critical paths
- **Height**: Analyzing algorithm efficiency, tree optimization

---

## 📖 Additional Resources

- [GeeksforGeeks - Binary Trees](https://www.geeksforgeeks.org/binary-tree-data-structure/)
- [Visualgo - Binary Tree Visualization](https://visualgo.net/en/bst)
- [LeetCode - Tree Problems](https://leetcode.com/tag/tree/)

---

## 🤝 Contributing

Feel free to:
- Add new tree algorithms
- Improve existing implementations
- Add more detailed comments
- Create test cases

---

## 📝 Notes

- All implementations use **pointers** for node connections
- Most algorithms are implemented **recursively**
- Code prioritizes **clarity** over micro-optimizations
- Each file is **self-contained** and can run independently

---

## ⚠️ Things to Remember

1. **Memory Management**: Remember to delete dynamically allocated nodes
2. **Edge Cases**: Handle empty trees and single-node trees
3. **BST Property**: Ensure left < root < right for all nodes
4. **Recursion**: Understand base cases to avoid stack overflow

---

**Happy Coding! 🚀**

*Last Updated: November 2024*
