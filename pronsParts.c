//This query looks for OV and VO clauses, where T is occupied by a finite auxiliary, and codes for object type and subject type to see how the relative informational content (i.e. surprisal), affects the OV/VO effect by clause type.

//****NOTE: clauses with traces in object position are currently excluded (see coding column 3). Extracted subjects could in theory be a relevant subject type, so they are coded separately, but they may be a mix of fairly informational (in subject questions) and very predictable (in relative clauses). Coding by clause type should also be done, but this will be in a separate query for sub clauses only. Matrix Qs and sub Qs with inversion are separated from embedded Qs below.

node: IP*
//add_to_ignore: \**
define: verbtopic.def
coding_query:


// 1: ov
// 0: vo
1: {
 \1: (IP* idoms object|RP) 
           AND (IP* idoms finite_aux)
    AND (IP* iDoms nonfin_mainverb)  AND (finite_aux precedes object|RP) AND (object|RP precedes nonfin_mainverb)

	\0: (IP* idoms object|RP) 
           AND (IP* idoms finite_aux)
    AND (IP* iDoms nonfin_mainverb) AND (finite_aux precedes nonfin_mainverb) AND (nonfin_mainverb precedes object|RP)

	z: ELSE
}


// MAT vs Qs with inversion vs other SUB clauses
2: {
	mat: (IP-MAT* idoms object|RP) 
    //CONJ has to be excluded because the C is up a level in those cases:
    invq: (IP-SUB* idoms object|RP) AND (IP-SUB* hassister !C|CONJ*)

    	sub: (IP-SUB* idoms object|RP) 

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


3:{

 qobj: (IP* idoms object) AND (object idoms Q*|NUM*|NEG|ONE*) AND (IP* idoms finite_aux) AND (finite_aux precedes object)
    
    both: (IP* idoms object) AND (object idomsonly PRO*) AND (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes object) AND (finite_aux precedes RP)
    
    pronobj: (IP* idoms object) AND (object idomsonly PRO*) AND (IP* idoms finite_aux) AND (finite_aux precedes object)
    
    rp: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (nonfin_mainverb idoms !*-búa|*-breyta|*-ræða|*-bera|*-geta|*-ferma|*-koma|*-ala|*-nema|*-selja|*-minna|*-kveða|*-leggja|*-flýja|*-vega|*-finna|*-ganga|*-reka|*-ræða|*-líta|*-klæða|*-leiða|*-una|*-sökkva|*-taka|*-vinna|*-steypa|*-bregða|*-hafa|*-halda|*-gefa|*-lifa|*-gá|*-leggja|*-skilja|*-búa|*-telja|*-renna|*-gnæfa|*-kljá|*-höggva|*-sökkva|*-ljóma|*-þekkja|*-henda)
    //AND (RP idoms !*-fyrir)
    
    posobj: (IP* idoms object) AND (object doms any_nominal|CONJ*|N*|D*) AND (IP* idoms finite_aux) AND (finite_aux precedes object)

    //Note that object traces will be in this later category and should be excluded:
    z: ELSE
  
}

//Subject status, including trace subjects ; these will behave differently in dif construction types: in rel clauses, the last over thing was the comp or the wh-word, i.e. low info, or the head word with a zero comp, which is higher info (but english only, not ice); in Qs, the preceding thing is a wh-word, so low info. Note: subject DO NOT NEED TO  precede objects IN THIS QUERY, BUT THEY DO IN THE INFO THEORY QUERIES.

4: {
  
 gapsbj: ((IP* idoms NP-SBJ*) AND (NP-SBJ* idomsonly \**) AND (IP* idoms object|RP)) OR (IP-*-*|IP-*=* idoms !NP-SBJ*)
     
     pronsbj: (IP* idoms NP-SBJ*) AND (NP-SBJ* idomsonly PRO*) AND (IP* idoms object|RP)
    
     nomsbj: (IP* idoms NP-SBJ*) AND (NP-SBJ* doms any_nominal|CONJ*|N*|D*) AND (IP* idoms object|RP) 
    
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
