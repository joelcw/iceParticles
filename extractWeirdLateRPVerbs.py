#This script extracts and prepares a list of inseparable prefixes from the history of Icelandic, for use in a coding query which will exclude them from use as siagnostics

import sys,string,re

fileString = sys.stdin.read()

letterList = []

for ii in string.ascii_letters:
    if ii != "z":
        letterList.append(ii)


regex = re.compile("(\(RP .+?(-.+?)\)\n\s*\(VB[PD].*?)(-.+?)\)", flags=re.MULTILINE)

matchList = regex.finditer(fileString)

ii = 0


for thing in matchList:
    sys.stdout.write("%s: (IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *%s) AND (nonfin_mainverb idoms *%s)\n\n" % (letterList[ii],thing.group(2),thing.group(3)))
    ii = ii+1
