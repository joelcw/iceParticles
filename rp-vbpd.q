#query for finding inseparable prefixes to exclude from set of diagnostics. Note that an overt subject is necessary in order to not catch stylistic fronting of RPs
add_to_ignore: \**
nodes_only:t
remove_nodes:t
define: verbtopic.def
node: IP*
query: (IP* idoms NP-SBJ*) AND (NP-SBJ* idoms .*) AND (IP* idoms finite_mainverb) AND (IP* idoms RP) AND (NP-SBJ* precedes RP) AND (RP iprecedes finite_mainverb)