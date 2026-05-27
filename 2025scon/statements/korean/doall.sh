cd ../../problems/alphabet-block/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/prize-game/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/seq-min-sum/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/n-way-intersection/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/even-sccc-scon/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/a-xor-b-equal-c/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/coloring/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/coprime-combination/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/divideteam/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/delicious-scon/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

latex statements.tex
latex statements.tex
dvips statements.dvi
dvipdfmx -p a4 statements.dvi
rm -f *.log
rm -f *.aux
rm -f *.dvi
rm -f *.ps
