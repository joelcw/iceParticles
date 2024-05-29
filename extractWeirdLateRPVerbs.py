#This script extracts and prepares a list of inseparable prefixes from the history of Icelandic, for use in a coding query which will exclude them from use as siagnostics

import sys,string,re

fileString = sys.stdin.read()


regex = re.compile("(\(RP .+?(-.+?)\)\n\s*\(VB[PD].*?)(-.+?)\)", flags=re.MULTILINE)

matchList = regex.finditer(fileString)


templateList = []

for thing in matchList:
    template = "(IP* idoms RP) AND (IP* idoms finite_aux) AND (finite_aux precedes RP) AND (IP* idoms nonfin_mainverb) AND (RP idoms *%s) AND (nonfin_mainverb idoms *%s)\n\n" % (thing.group(2),thing.group(3))
    if template not in templateList:
        templateList.append(template)

for thing in templateList:
    sys.stdout.write("insep: %s" % (thing)) 
