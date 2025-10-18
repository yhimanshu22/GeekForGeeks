<h2><a href="https://www.geeksforgeeks.org/problems/max-heap-implementation/1?page=3&category=Heap&sortBy=submissions">Max Heap implementation</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Implement a class&nbsp;<strong>maxHeap&nbsp;</strong>that supports the following operations:</span></p>
<ul>
<li><span style="font-size: 14pt;">push(x) –&nbsp;push element x into the heap</span></li>
<li><span style="font-size: 14pt;">pop() – remove the top element from the heap</span></li>
<li><span style="font-size: 14pt;">peek() – return top element from the heap, if empty return -1</span></li>
<li><span style="font-size: 14pt;">size() - return the no of elements in the heap.</span></li>
</ul>
<p><span style="font-size: 14pt;">There will be a sequence of queries&nbsp;<strong>queries[][]</strong>. The queries are represented in numeric form:</span></p>
<ul>
<li><span style="font-size: 14pt;">1 x : call push(x)</span></li>
<li><span style="font-size: 14pt;">2: call pop()</span></li>
<li><span style="font-size: 14pt;">3: call peek()</span></li>
<li><span style="font-size: 14pt;">4: call size()</span></li>
</ul>
<p><span style="font-size: 14pt;">The driver code will process the queries, call the corresponding functions, and print the outputs of peek(), size() operation.</span></p>
<p><span style="font-size: 14pt;">You only need to implement the above four functions.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>q = 5, queries[][] = [[1, 3], [1, 7], [3], [1, 2], [3]]
<strong>Output:</strong> [7, 7]
<strong>Explanation:</strong>
push(3): heap is [3]</span><br><span style="font-size: 14pt;">push(7): heap is [7, 3]</span><br><span style="font-size: 14pt;">peek(): return top element 7</span><br><span style="font-size: 14pt;">push(2): heap is [7, 3, 2]<br></span><span style="font-size: 14pt;">peek(): return top element 7</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>q = 6, queries[][] = [[1, 4], [1, 8], [1, 7], [2], [3], [4]]
<strong>Output:</strong> [7, 2]
<strong>Explanation:</strong>
push(4): heap is [4]<br>push(8): heap is [8, 4]</span><br><span style="font-size: 14pt;">push(7): heap is [8, 7, 4]<br>pop(): remove top element 8, now heap is [7, 4]</span><br><span style="font-size: 14pt;">peek(): return top element 7</span><br><span style="font-size: 14pt;">size(): return no of elements in the heap</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ q ≤ 10<sup>3</sup><br>1 ≤ x ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Heap</code>&nbsp;<code>STL</code>&nbsp;<code>Data Structures</code>&nbsp;