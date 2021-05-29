<h2>1541. Minimum Insertions to Balance a Parentheses String</h2><h3>Medium</h3><hr><div><p>Given a parentheses string <code>s</code> containing only the characters <code>'('</code> and <code>')'</code>. A parentheses string is <strong>balanced</strong> if:</p>

<ul>
	<li>Any left parenthesis&nbsp;<code>'('</code>&nbsp;must have a corresponding two consecutive right parenthesis&nbsp;<code>'))'</code>.</li>
	<li>Left parenthesis&nbsp;<code>'('</code>&nbsp;must go before the corresponding two&nbsp;consecutive right parenthesis&nbsp;<code>'))'</code>.</li>
</ul>

<p>In other words, we treat <code>'('</code> as openning parenthesis and <code>'))'</code> as closing parenthesis.</p>

<p>For example, <code>"())"</code>, <code>"())(())))"</code> and <code>"(())())))"</code> are&nbsp;balanced, <code>")()"</code>, <code>"()))"</code> and <code>"(()))"</code> are not balanced.</p>

<p>You can insert the characters <code>'('</code> and <code>')'</code> at any position of the string to balance it if needed.</p>

<p>Return <em>the minimum number of insertions</em> needed to make <code>s</code> balanced.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(()))"
<strong>Output:</strong> 1
<strong>Explanation:</strong> The second '(' has two matching '))', but the first '(' has only ')' matching. We need to to add one more ')' at the end of the string to be "(())))" which is balanced.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "())"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already balanced.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "))())("
<strong>Output:</strong> 3
<strong>Explanation:</strong> Add '(' to match the first '))', Add '))' to match the last '('.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "(((((("
<strong>Output:</strong> 12
<strong>Explanation:</strong> Add 12 ')' to balance the string.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = ")))))))"
<strong>Output:</strong> 5
<strong>Explanation:</strong> Add 4 '(' at the beginning of the string and one ')' at the end. The string becomes "(((())))))))".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code> consists of <code>'('</code> and <code>')'</code> only.</li>
</ul>
</div>