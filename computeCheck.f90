!
! ProjectF
! computeCheck.f90
! CS4080 - Raheja - Group Final Project
! Jake Wagner, Chris Rauch, Scott Ha
! 
! This file is the main driver for our FORTRAN project. It contains
! implementations of several different computaionally intensive
! algorithms. It times its own performance for these and calls the 
! related implemenation of the algorithm in other programming langauges
! so as to compare performace to them as well.
!
!  IMPORTANT NOTE: No values for input to the algorithms are passed to 
!		the other implementations in the other langauges. Please ensure
!		the hard-coded values match for each.
!
PROGRAM computeCheck
IMPLICIT NONE
!RESOURCES
REAL :: start_time, stop_time 	! clocks for timing the algorithms
INTEGER :: i, j, k				!counters
INTEGER :: row = 800, col = 800		! Dims for Matrix Multiplication
INTEGER, DIMENSION(800, 800) :: a, b, c

!COMPARISON of MATRIX MULTIPLICATION =================================
PRINT*,"=== COMPARISON of MATRIX MULTIPLICATION ==="
CALL SYSTEM('./matrixMulc')
!CALL SYSTEM('./matrixMul.java')

!initialize A and B
DO i = 1, row
DO j = 1, col
a(i, j) = MOD((i+j), 100) 
b(i, j) = MOD((i+j), 100) 
END DO
END DO

! Start clock
CALL cpu_time(start_time)
! Multiply A and B
DO i = 1, row
DO j = 1, col
C(i, j) = 0
DO k = 1, col
c(i, j) = c(i, j) + (a(i, k) * b(k, j))
ENDDO
END DO
END DO
! Stop clcok
CALL cpu_time(stop_time)

!CALL printMat(c, row, col) !If display of matrix is required

!display time spent running algorithm   
PRINT *,"Fortran: ", (stop_time - start_time), "seconds"
!END Cmp of Matrix Mul ===============================================
      
END PROGRAM computeCheck



SUBROUTINE printMat(mat, i, j)
IMPLICIT NONE

!Dummy vaiables
INTEGER, INTENT(IN) :: i,j
INTEGER, INTENT(IN) :: mat(i,j)

!local variable
INTEGER :: X

DO  x = 1, i
print '(20i6.2)',mat(x,1:j)
END DO
END SUBROUTINE
