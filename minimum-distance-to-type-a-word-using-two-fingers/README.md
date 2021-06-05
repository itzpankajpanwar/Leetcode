<h2>1320. Minimum Distance to Type a Word Using Two Fingers</h2><h3>Hard</h3><hr><div><p><img alt="" src="https://assets.leetcode.com/uploads/2020/01/02/leetcode_keyboard.png" style="width: 417px; height: 250px;"></p>

<p>You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, for example, the letter <strong>A</strong> is located at coordinate <strong>(0,0)</strong>, the letter <strong>B</strong> is located at coordinate <strong>(0,1)</strong>, the letter <strong>P</strong> is located at coordinate <strong>(2,3)</strong> and the letter <strong>Z</strong> is located at coordinate <strong>(4,1)</strong>.</p>

<p>Given the string <code>word</code>, return the minimum total distance to type such string using only two&nbsp;fingers. The distance between coordinates <strong>(x<sub>1</sub>,y<sub>1</sub>)</strong> and <strong>(x<sub>2</sub>,y<sub>2</sub>)</strong> is <strong>|x<sub>1</sub> - x<sub>2</sub>| + |y<sub>1</sub> - y<sub>2</sub>|</strong>.&nbsp;</p>

<p>Note that the initial positions of your two&nbsp;fingers are considered free so don't count towards your total distance, also your two&nbsp;fingers do not have to start at the first letter or the first two&nbsp;letters.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word = "CAKE"
<strong>Output:</strong> 3
<strong>Explanation: 
</strong>Using two fingers, one optimal way to type "CAKE" is: 
Finger 1 on letter 'C' -&gt; cost = 0 
Finger 1 on letter 'A' -&gt; cost = Distance from letter 'C' to letter 'A' = 2 
Finger 2 on letter 'K' -&gt; cost = 0 
Finger 2 on letter 'E' -&gt; cost = Distance from letter 'K' to letter 'E' = 1 
Total distance = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word = "HAPPY"
<strong>Output:</strong> 6
<strong>Explanation: </strong>
Using two fingers, one optimal way to type "HAPPY" is:
Finger 1 on letter 'H' -&gt; cost = 0
Finger 1 on letter 'A' -&gt; cost = Distance from letter 'H' to letter 'A' = 2
Finger 2 on letter 'P' -&gt; cost = 0
Finger 2 on letter 'P' -&gt; cost = Distance from letter 'P' to letter 'P' = 0
Finger 1 on letter 'Y' -&gt; cost = Distance from letter 'A' to letter 'Y' = 4
Total distance = 6
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word = "NEW"
<strong>Output:</strong> 3
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> word = "YEAR"
<strong>Output:</strong> 7
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= word.length &lt;= 300</code></li>
	<li>Each <code data-stringify-type="code">word[i]</code>&nbsp;is an English uppercase letter.</li>
</ul></div>