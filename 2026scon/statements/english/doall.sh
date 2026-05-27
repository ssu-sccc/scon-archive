cd ../../problems/where-is-my-icp/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/soongsil-station/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/cream-first-jam-first/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/lexicographical-minimum/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/flip-range/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/unique-range-easy/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/evaluate/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/make-same/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/god-of-trouble/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/scon-magic-graph/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/xor-palindrome/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/snake-seq/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/pspoker/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/unique-range/statements/english
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/find/statements/english
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
