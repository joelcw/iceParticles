 CS="java -classpath /home/joelcw/CurrentLx/OldNorse/CS_2.003.04.jar csearch/CorpusSearch"

icepahc="/home/joelcw/icecorpus/finished/*.psd"

rm outputs/pronsParts.ice.nodates.cod
$CS pronsParts.c $icepahc -out outputs/pronsParts.ice.nodates.cod

echo "done with query on IcePaHC"

$CS dateGenre.ice.c outputs/pronsParts.ice.nodates.cod -out outputs/pronsParts.ice.raw.cod

echo "done with dating IcePaHC data"

#Some things are commented out below so that we can make a raw version with full IDs that Anton can use

rm outputs/pronsParts.ice.raw.cod.ooo
$CS codes.q outputs/pronsParts.ice.raw.cod

echo "Done with study on icepahc"



python3 fixIdFormat.ice.py < outputs/pronsParts.ice.raw.cod.ooo > outputs/pronsParts.ice.cod.ooo.tmp
mv outputs/pronsParts.ice.treeIDandIDfixed.cod.ooo outputs/pronsParts.ice.treeIDandIDfixed.cod.ooo.old
mv outputs/pronsParts.ice.cod.ooo.tmp outputs/pronsParts.ice.treeIDandIDfixed.cod.ooo

echo "Fixed codes"
