nodes_only:t
remove_nodes:t
node: CODING*
query: (CODING-IP* column 3 rp)
AND
(CODING-IP* column 1 \1)
AND
(CODING-IP* column 5 \1\9*|\2*)