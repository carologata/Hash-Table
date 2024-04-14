# Hash-Table

![image](https://github.com/carologata/Hash-Table/assets/105884639/8d9d6a70-5ace-4ec3-b9ce-642919c2638d)

Combine advantages of both types of data structure - arrays and linked lists, while decreasing their disadvantages.

- Insertion can tend toward θ(1)
- Deletion can tend toward θ(1)
- Lookup can tend toward θ(1)

The hash function should:
 - Use only the data being hashed
 - Use all of the data being hashed
 - Be deterministic
 - Uniformly distribute data
 - Generate very different hash codes for very similar data

Resolving collisions:
 - Linear probing -> problem: clustering
 - Chaining

Source:
 - CS50: https://www.youtube.com/watch?v=nvzVHwrrub0&ab_channel=CS50
 - Jacob Sorber: https://www.youtube.com/watch?v=2Ti5yvumFTU&ab_channel=JacobSorber
