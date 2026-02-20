! Function for generating bad random numbers. 
! Converted to C code using the same logic in "bad_rand.c"       

      real(8) function bad_rnd()
              implicit none
              integer :: iran = 13337
              common / bad_rndpar /iran
              integer, parameter :: m = 131072 ! equal 2**17
              integer, parameter :: a =1277

              iran = a*iran
              iran = MOD(iran, m)

              bad_rnd = iran/DBLE(m)

      end function bad_rnd
