cd ../../problems/irritable-bowel-syndrome/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/team-name-2/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/concat/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/visit-all-easy/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/modify-expression/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/fibonacci-partition/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/create-timetable/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/fork/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/beautiful-fireworks/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/or-path/statements/korean
for file in ./*.mp
do
    [ -e $file ] && mpost $file
done
rm -f *.log
cd -

cd ../../problems/visit-all/statements/korean
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
