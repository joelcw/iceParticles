nodes_only:t
remove_nodes:t
define: verbtopic.def
node: IP*
query:
IP* idoms CODING-IP*
AND
(CODING-IP* column 3 both)
AND
(CODING-IP* column 1 \1)
AND
IP* idoms nonfin_verb
AND
IP* idoms RP
AND
nonfin_verb precedes RP