<h2>753. Cracking the Safe</h2><h3>Hard</h3><hr><div><p>There is a box protected by a password. The password is a sequence of <code>n</code> digits where each digit can be in the range <code>[0, k - 1]</code>.</p>

<p>While entering a password, the last <code>n</code> digits entered will automatically be matched against the correct password.</p>

<ul>
	<li>For example, assuming the correct password is <code>"345"</code>, if you type <code>"012345"</code>, the box will open because the correct password matches the suffix of the entered password.</li>
</ul>

<p>Return <em>any password of minimum length that is guaranteed to open the box at some point of entering it</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 2
<strong>Output:</strong> "10"
<strong>Explanation:</strong> "01" will be accepted too.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2, k = 2
<strong>Output:</strong> "01100"
<strong>Explanation:</strong> "01100", "10011", "11001" will be accepted too.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 4</code></li>
	<li><code>1 &lt;= k &lt;= 10</code></li>
	<li><code>1 &lt;= k<sup>n</sup> &lt;= 4096</code></li>
</ul>
</div>