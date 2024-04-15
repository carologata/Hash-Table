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

# Application

Hash table applied on a Leet Code exercise Two Sum:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

The code LeetCode_Two_Sum.c file represents θ(n) since for each value n-1 values are walked through.
It is possible to see the runtime from Leet Code exercise submission below.

![Captura de tela de 2024-04-14 21-28-24](https://github.com/carologata/Hash-Table/assets/105884639/cf68ced4-9846-4fab-8e99-bd95573fcd11)

The code LeetCode_Two_Sum_Optimized.c file tries to get close to θ(1) with application of hash table.
It is also possible to see the runtime from Leet Code exercise submission below.

![Captura de tela de 2024-04-14 21-29-13](https://github.com/carologata/Hash-Table/assets/105884639/79e518c4-3c44-4b9f-a511-c3dc5e7cd423)
