#define R 7
#define S 5
#define T 8

long A[R][S][T];

long
ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}

/*
1) &D[a][b][c] = Dx + L((S * T * a) + (T * b) + c)
2) Breakdown of machine code
	movl	$7, %eax				:7			
	subq	%rdi, %rax				:7 - i
	leaq	(%rax,%rax,4), %rax		:5(7 - i)
	subq	%rsi, %rax				:5(7 - i) - j
	leaq	7(%rdx,%rax,8), %rax	:8(5(7 - i) - j) + k + 7
									=(8 * 5 * (7 - i)) - 8j + k + 8 -1
									=(8 * 5 * (7 - i)) + 8(1 - j) + (k - 1)
	matching the equation from #1, showing that R = 7, S = 5 and T = 8
*/