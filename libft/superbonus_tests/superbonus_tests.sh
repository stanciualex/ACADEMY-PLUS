cp *_test.c ../
cd ..
gcc ft_isprime*
./a.out
echo '\n'
gcc ft_islower*
./a.out
echo '\n'
gcc ft_isupper*
./a.out
echo '\n'
gcc ft_swap*
./a.out
echo '\n'
gcc ft_strlower* ft_tolower.c
./a.out
echo '\n'
gcc ft_strupper* ft_toupper.c
./a.out
echo '\n'
rm -rf *test.c
rm -rf a.out
