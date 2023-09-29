
include_guard(GLOBAL)

check_c_compiles("
int
main (void)
{
  typeof (main) var;
  return 0;
}
" HAVE_TYPEOF)

check_c_compiles("
int
main (void)
{
  __typeof__ (main) var;
  return 0;
}
" HAVE___TYPEOF__)
