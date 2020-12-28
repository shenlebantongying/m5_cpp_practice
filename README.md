m5
===

C++ practice.

A simple text replacement library like GNU M4 or Liquid

```
template.txt + substitution.txt => result.txt
```

Only support `{name} => real name` :)

```asm
>> substitutions:
key: name replacement: nice
key: name2 replacement: cool

>> original text:
This is a text message:
I am {name}.
Hi, I am {name2}.

>> replaced text:
This is a text message:
I am nice.
Hi, I am cool.
```
