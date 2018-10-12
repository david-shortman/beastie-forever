~~

<smaller>A</smaller>

Prototypical

<bigger>Quiz</bigger>


**
<only latex>
Always choose the correct answer.


</only>
%% '''Concept:''' ''Sections'' (sections begin with <percent/>,,<percent/>)

'''''Concept inventory developers should understand sections, section
headings, and selections.'''''

!! This selection markup says to choose three questions randomly
{{3
?? This is the first question. Is it a good won?
    && no, it has no content
    &&^no, you misspelled a word       !!&&^ marks the correct answer
    && no, it's too easy to answer
    && yes, I like it.

!! This selection markup says to choose one question randomly. Since
!! it is nested within a selection, it must be a one-question selection.
!! A one-question selection starts with {{1 or {{.
{{
?? Do you like to read?
    && ''only in italics''
    && '''only in bold'''
    && '''''only in bold italics'''''
    && @@only in typewriter font@@
    &&^<bigger>only in a bigger font</bigger>
    && <smaller>only in a smaller font</smaller>

!! This question shows how questions with alternatives are made. You
!! need to request the alternative form; it will be sent via email if
!! you check the checkbox on the form version of the quiz. To receive
!! emails, you need to make a request to get your email approved.
?? What do you make of {{.this.this code}}?
@@
    function {{.gcd(a,b).gcd(b,c)}}
        {
        if ({{.b.c}} == 0)
            return a;
        else
            return {{.gcd(b,a % b).gcd(c,b % c)}};
        }
@@
    && Wut?
    && Aaah, Euclid
    &&^Uses constant space if tail recursion is optimized
    && Recursion is not space-efficient
}}
!! we just ended the nested selection

??
<span style="background-color: pink;">
Did you know you can use html5 tags, too?
</span>
    &&^yes
    && does LaTeX go bonkers?
    && what is html5?
    && let's not get too fancy here

?? Hey, look at these Roman numerals!
    * MM
    * DCLXVI
    * CDXLIV
    * &Vbar;MMMDCCCLXXXVIII
    ^^
Which is the coolest?
   && the first one
   && the second one
   && the third one
   &&^the fourth one

?? Did you know you can fill in the blank?
Place your answer in the space provided below.
;;4
<line>200</line>
^^
}}

%% '''Concept:''' ''Drawing''

'''''Concept inventory developers should color between the lines.'''''

{{
?? Can you figure out the voltage drop across the resistor
in this circuit?
Assume the wires have no resistance.
!! This is how you draw circuts
+++
    (include "drawEE.scm")
    (battery up {{.12.24}} volts polarity)
    (wire right 3)
    (resistor down 10 kiloohms)
    (wire left 3)

+++
    &&^Sure, all of the {{.12.24}} volts drops across the single resistor
    && Sure, {{.24.12}} volts drops across the resistor
    && No, I work on a far higher plane
    && 
    <only latex>
    I dropped out of circus school
    </only>
    <only html5 form>
    If I wanted to answer circus questions, I would have gotten a circus degree
    </only>
    && Which one is the resistor?

?? What does this look like?
+++
    (include "drawCS.scm")
    (linkedList "alpha" 1 2 3 4)
+++
    && a bunch of boxes and arrows
    && a heap
    && a data structure that would make a great queue
    &&^a data structure that would make a great stack
}}

%% '''Concept:''' ''Math''

'''''Concept inventory developers should understand how
to do math.'''''

?? What equation is this:
        $x = \frac{-b \pm \sqrt{b^2 - 4ac} }{2a}$
    && you can do equations in html now??!?
    && the ''example.q'' file has backslashes in the equation!
    &&^the quadractic?
    && how did you do that equation? LaTeX?

?? Because this concept inventory system uses LaTeX for math, images, and
PDFs and uses HTML for web pages and forms,
you need to treat which of the following symbols specially?
    && <sharp/>, using @@<sharp/>@@
    && <dollar/>, using @@<dollar/>@@
    && <underscore/>, using @@<underscore/>@@
    && <percent/>, using @@<percent/>@@
    && <ampersand/>, using @@<ampersand/>@@
    && <tilde/>, using @@<tilde/>@@
    && <caret/>, using @@<caret/>@@
    && <obrace/>, using @@<obrace/>@@
    && <cbrace/>, using @@<cbrace/>@@
    && <backslash/>, using @@<backslash/>@@
    && <lt/>, using @@<lt/>@@
    && <gt/>, using @@<gt/>@@
    &&^all listed
    && none listed

?? '''True''' or '''False''': 
You can force a space using the @@<sp/>@@ tag.
    && true

?? '''True''' or '''False''': 
You can suppress a space using the @@,,@@ tag.
    && true

?? Did you notice that the questions in this section
are always selected when you randomize selections on
the form?
    && what form?
    &&^yes, because they aren't in a random selection block
    && no, I haven't played around with the form version yet
    && do you mean this
    <url http://troll.cs.ua.edu/concepts/example/example.form>form</url>?
    && do you mean: <link>/concepts/example/example.form</link>?
