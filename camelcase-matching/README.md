<h2>1023. Camelcase Matching</h2><h3>Medium</h3><hr><div><p>A query word matches a given <code>pattern</code> if we can insert <strong>lowercase</strong> letters to the pattern word so that it equals the <code>query</code>. (We may insert each character at any position, and may insert 0 characters.)</p>

<p>Given a list of <code>queries</code>, and a <code>pattern</code>, return an <code>answer</code> list of booleans, where <code>answer[i]</code> is true if and only if <code>queries[i]</code> matches the <code>pattern</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>queries = <span id="example-input-1-1">["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]</span>, pattern = <span id="example-input-1-2">"FB"</span>
<strong>Output: </strong><span id="example-output-1">[true,false,true,true,false]</span>
<strong>Explanation: </strong>
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>queries = <span id="example-input-2-1">["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]</span>, pattern = <span id="example-input-2-2">"FoBa"</span>
<strong>Output: </strong><span id="example-output-2">[true,false,true,false,false]</span>
<strong>Explanation: </strong>
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong>queries = <span id="example-input-3-1">["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"]</span>, pattern = <span id="example-input-3-2">"FoBaT"</span>
<strong>Output: </strong><span id="example-output-3">[false,true,false,false,false]</span>
<strong>Explanation: </strong>
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= queries.length &lt;= 100</code></li>
	<li><code>1 &lt;= queries[i].length &lt;= 100</code></li>
	<li><code>1 &lt;= pattern.length &lt;= 100</code></li>
	<li>All strings consists only of lower and upper case English letters.</li>
</ol>
</div>