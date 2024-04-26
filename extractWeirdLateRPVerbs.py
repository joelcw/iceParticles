import sys,string,re

fileString = sys.stdin.read()

regex = re.compile("(\(RP .+?\)\n\s*\(V.*?)(-.+?)\)", flags=re.MULTILINE)

matchList = regex.finditer(fileString)

for thing in matchList:
    sys.stdout.write("%s|" % thing.group(2))
