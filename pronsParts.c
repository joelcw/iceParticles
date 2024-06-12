//This query looks for OV and VO clauses, where T is occupied by a finite auxiliary, and codes for object type and subject type to see how the relative informational content (i.e. surprisal), affects the OV/VO effect by clause type.

//****NOTE: clauses with traces in object position are currently excluded (see coding column 3). Extracted subjects could in theory be a relevant subject type, so they are coded separately, but they may be a mix of fairly informational (in subject questions) and very predictable (in relative clauses). Coding by clause type should also be done, but this will be in a separate query for sub clauses only. Matrix Qs and sub Qs with inversion are separated from embedded Qs below.

node: IP*
//add_to_ignore: \**
define: verbtopic.def
coding_query:


// 1: ov
// 0: vo
1: {
 \1: (IP* idoms object|RP|IP-SMC*|IP-PPL*) 
           AND (IP* idoms finite_aux)
    AND (IP* iDoms nonfin_mainverb)  AND (finite_aux precedes object|RP|IP-SMC*|IP-PPL*) AND (object|RP|IP-SMC*|IP-PPL* precedes nonfin_mainverb)

	\0: (IP* idoms object|RP|IP-SMC*|IP-PPL*) 
           AND (IP* idoms finite_aux)
    AND (IP* iDoms nonfin_mainverb) AND (finite_aux precedes nonfin_mainverb) AND (nonfin_mainverb precedes object|RP|IP-SMC*|IP-PPL*)

	z: ELSE
}


// MAT vs Qs with inversion vs other SUB clauses
2: {
	mat: (IP-MAT* idoms object|RP|IP-SMC*|IP-PPL*) 
    //CONJ has to be excluded because the C is up a level in those cases:
    invq: (IP-SUB* idoms object|RP|IP-SMC*|IP-PPL*) AND (IP-SUB* hassister !C|CONJ*)

    	sub: (IP-SUB* idoms object|RP|IP-SMC*|IP-PPL*) 

        z: ELSE

    
/*         indirectq:   (CP-QUE* iDoms IP-SUB*) AND (CP-QUE* iDoms C)
     cpthat:   (CP-THT* idoms IP-SUB*) AND (CP-THT* iDoms C)
    cpdeg:   (CP-DEG* idoms IP-SUB*) AND (CP-DEG* iDoms C)
     cpadv:	  (CP-ADV* idoms IP-SUB*) AND (CP-ADV* iDoms C)
     cprel:   (CP-REL*|CP-FRL* idoms IP-SUB*) AND (CP-REL*|CP-FRL* iDoms C)
    cpcar:   (CP-CAR* idoms IP-SUB*) AND (CP-CAR* iDoms C)
    cpcmp:   (CP-CMP* idoms IP-SUB*) AND (CP-CMP* idoms C)
*/
}

//diagnostic is: both diagnostics in same clause, or pronoun, or particle. Auxs are constrained to precede so that we don't get "both" examples with top or stylistic fronting.
//This query now excludes a number of verbs in particle constructions, in the rp case only. These can be found in the iceParts directory verbsWithRPsToExclude.txt, with the Python file used to generate them from outputs/late-rps.out. These are all verbs that appear with pre-verbal particles in the 20th and 21st century portions of the corpus.


//The massive list of "insep" are inseparable prefixes to exclude from the "rp" code

3:{

 qobj: (IP* idoms object) AND (object idoms Q*|NUM*|NEG|ONE*) AND (IP* idoms finite_aux) AND (finite_aux precedes object)
    
    both: (IP* idoms object) AND (object idomsonly PRO*) AND (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes object) AND (finite_aux precedes RP)
    
    pronobj: (IP* idoms object) AND (object idomsonly PRO*) AND (IP* idoms finite_aux) AND (finite_aux precedes object)

    smc: (IP* idoms IP-SMC*|IP-PPL*) AND (IP* idoms finite_aux) AND (finite_aux precedes IP-SMC*|IP-PPL*) AND (IP* idoms nonfin_mainverb)

    
    //BEGIN list of inseparables from entire corpus

    insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-of) AND (nonfin_mainverb idoms *-marka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-of) AND (nonfin_mainverb idoms *-ná)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-of) AND (nonfin_mainverb idoms *-taka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-gefa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-líta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-dæma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-víta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-fara)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-láta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-sjá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-klæða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-kafa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-flytja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-bjóða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-ljúka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-kringja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-snúa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-leysa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-bæta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-brjóta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-heyra)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-gefa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-kveikja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-vinna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-velja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-með) AND (nonfin_mainverb idoms *-taka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-neita)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-vekja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-setja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-skúfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-of) AND (nonfin_mainverb idoms *-sækja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-lífa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-teikna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-setja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-leiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-minna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-leysa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-spyrja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-leggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-festa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-sigla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-biðja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-virða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-hefja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-með) AND (nonfin_mainverb idoms *-kenna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-reka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-senda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-fylla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-sperra)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-stíga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-leggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-reiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-byggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-fyllast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-breiðast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-láta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-rætast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-reikna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-eta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-arma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-girða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-vísa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-þrykkja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-hafast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-buga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-telja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-of) AND (nonfin_mainverb idoms *-bjóða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-svelgja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-gæta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-binda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-undir) AND (nonfin_mainverb idoms *-standa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-vaxta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-búa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-stíga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-liggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-slétta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-troða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-klaga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-gefa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-falla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-hella)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-drífa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-skafa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-sökkva)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-þvo)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-gefa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-standa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-reka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-breiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-vega)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-lykta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-nægja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-ráða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-leiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-breyta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-fara)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-flytja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-taka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-með) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-bevísa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-ég) AND (nonfin_mainverb idoms *-þurfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-saka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-falla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-frá) AND (nonfin_mainverb idoms *-segja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-kanna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-hæfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-nauðsynja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-vísa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-leiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-svalla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-lýsa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-fella)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-fýsa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-slá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-lossa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-láta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-hlýða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-skilja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-liggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-víkja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-með) AND (nonfin_mainverb idoms *-þurfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-falla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-frá) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-spila)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-eggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-hjá) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-hrökkva)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-halda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-hræra)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-setja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-vilja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-lykja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-liggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-ráða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-skilja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-með) AND (nonfin_mainverb idoms *-fylgja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-telja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-rækjast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-lifa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-tala)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-rísa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-vakna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-líta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-þurfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-ljóma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-setja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-reisa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-víkja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-gangast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-rækja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-gnæfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-ausa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-búa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-kalla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-taka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-fara)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-nefna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-mæla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-slá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-flæmast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-deila)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-plána)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-leggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-senda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-henda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-nefna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-rætast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-setja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-renna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-úr) AND (nonfin_mainverb idoms *-skurða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-þýða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-götvast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-vinna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-greina)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-rétta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-leita)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-erta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-falla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-prenta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-þrengja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-ræta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-mála)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-leysa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-segja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-söka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-kaupa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-grafa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-stoða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-standa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-ná)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-bjóða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-fylgja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-þykja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-lista)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-málga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-sjá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-fá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-varpa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-girnast)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-sá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-forma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-of) AND (nonfin_mainverb idoms *-selja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-saka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-stunda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-sala)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-leiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-sækja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-leita)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-skýra)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-færa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-hylla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-búa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-lýsa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-kveða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-kynna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-varpa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-þakka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-hverfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-ljúka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-kalla)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-götva)

    //END list of inseparables from entire corpus


    //BEGIN list of inseparables from late period with nonfin verbs


insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-búa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-breyta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-ræða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-bera)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-geta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-ferma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-ala)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-nema)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-selja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-minna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-kveða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-leggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-flýja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-vega)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-finna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-ganga)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-reka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-inn) AND (nonfin_mainverb idoms *-ræða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-líta)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-klæða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fram) AND (nonfin_mainverb idoms *-leiða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-una)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-sökkva)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-taka)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-vinna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-steypa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-bregða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-fyrir) AND (nonfin_mainverb idoms *-gefa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-hafa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-við) AND (nonfin_mainverb idoms *-halda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-gefa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-lifa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-gá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-leggja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-að) AND (nonfin_mainverb idoms *-skilja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-á) AND (nonfin_mainverb idoms *-kveða)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-til) AND (nonfin_mainverb idoms *-búa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-undir) AND (nonfin_mainverb idoms *-búa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-niður) AND (nonfin_mainverb idoms *-koma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-telja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-renna)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-yfir) AND (nonfin_mainverb idoms *-gnæfa)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-út) AND (nonfin_mainverb idoms *-kljá)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-höggva)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-upp) AND (nonfin_mainverb idoms *-ljóma)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-þekkja)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-af) AND (nonfin_mainverb idoms *-henda)

insep: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *-um) AND (nonfin_mainverb idoms *-ganga)

    //END list of inseparables from the later part of the corpus with nonfin verbs
    
    rp: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb)


    //AND (nonfin_mainverb idoms !*-búa|*-breyta|*-ræða|*-bera|*-geta|*-ferma|*-koma|*-ala|*-nema|*-selja|*-minna|*-kveða|*-leggja|*-flýja|*-vega|*-finna|*-ganga|*-reka|*-ræða|*-líta|*-klæða|*-leiða|*-una|*-sökkva|*-taka|*-vinna|*-steypa|*-bregða|*-hafa|*-halda|*-gefa|*-lifa|*-gá|*-leggja|*-skilja|*-búa|*-telja|*-renna|*-gnæfa|*-kljá|*-höggva|*-sökkva|*-ljóma|*-þekkja|*-henda)
    
    
    posobj: (IP* idoms object) AND (object doms any_nominal|CONJ*|N*|D*) AND (IP* idoms finite_aux) AND (finite_aux precedes object)


    //Note that object traces will be in this later category and should be excluded:
    z: ELSE
  
}

//Subject status, including trace subjects ; these will behave differently in dif construction types: in rel clauses, the last over thing was the comp or the wh-word, i.e. low info, or the head word with a zero comp, which is higher info (but english only, not ice); in Qs, the preceding thing is a wh-word, so low info. Note: subject DO NOT NEED TO  precede objects IN THIS QUERY, BUT THEY DO IN THE INFO THEORY QUERIES.

4: {
  
 gapsbj: ((IP* idoms NP-SBJ*) AND (NP-SBJ* idomsonly \**) AND (IP* idoms object|RP|IP-SMC*|IP-PPL*)) OR (IP-*-*|IP-*=* idoms !NP-SBJ*)
     
     pronsbj: (IP* idoms NP-SBJ*) AND (NP-SBJ* idomsonly PRO*) AND (IP* idoms object|RP|IP-SMC*|IP-PPL*)
    
     nomsbj: (IP* idoms NP-SBJ*) AND (NP-SBJ* doms any_nominal|CONJ*|N*|D*) AND (IP* idoms object|RP|IP-SMC*|IP-PPL*) 
    
    z: ELSE
    }


/*
// time period
5: {


// first line sets aside translations and archaic texts; note that the last two are in IcePaHC, but you may want to put these back in (and/or exlude other weird icepahc texts too)
      \0:  (AUTHNEW*|AUTHOLD*|BOETHEL*|ERV-*|NEWCOME-*|PURVER-*|TYNDNEW*|TYNDOLD*|CMAYEN*|CMBRUT3*|CMLAMB*|NTACTS*|NTJOHN* inID)


//Rough time periods for YCOE texts (Old English)

    \800:  (codocu1* inID)
    \850: (codocu2*|cobede*|coboeth*|cocura*|colaece*|colawaf*|colawafint*|coorosiu*|coprefcura* inID)
      \950:  (coalex*|coblick*|cochad*|cochronA*|codocu3*|codocu4*|cogregdC*|cogregdH*|colacnu*|comart3*|comarvel*|coquadru* inID)
    \1000:  (coaelhom*|coaelive*|coapollo*|cobenrul*|cobyrhtf*|cocathom1*|cocathom2*|codocu3*|coepigen*|colaw1cn*|colaw2cn*|colaw5atr*|colaw6atr*|colawnorthu*|colsigef*|colwstan1*|colwstan2*|cootest*|coprefcath1*|coprefcath2*|coprefgen*|copreflives*|cotempo*|cowsgosp* inID)
    \1050:  (coadrian*|cochronE*|codicts*|coinspolD*|colawger*|colsigewZ*|colwsigeXa*|comargaC*|cowulf* inID) 
    \1100: (colawwllad*|coleofri*|cosolsat1* inID)


//No dates for ppche because I'll use metadata

    NA: ELSE
}

*/
