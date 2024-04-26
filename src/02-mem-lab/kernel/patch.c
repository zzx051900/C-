/* --------------------------------------------------------------
 * File          : patch.c
 * Authors       : 西安电子科技大学:网络与信息安全国家级实验教学中心
 * Created on    : <2024-02-01>
 * Last modified : <2024-03-01>
 * LICENSE       : 由实验教学中心拥有，分发需申请并征得同意
 * -------------------------------------------------------------*/

// =================================================
// 1. arch/x86/entry/syscalls/syscall_64.tbl
// 文件末尾添加
548	common peep_page        sys_peep_page



// =================================================
// 2. include/linux/syscalls.h
// 文件末尾最后的#endif前添加
asmlinkage long sys_peep_page(pid_t tar_pid_nr, unsigned long tar_addr, unsigned long my_addr);
#endif



// =================================================
// 3. include/uapi/asm-generic/unistd.h
#undef __NR_syscalls
#define __NR_syscalls 451
// 放在这个下面
#define __NR_peep_page 548
__SYSCALL(__NR_peep_page, sys_peep_page)



// =================================================
// 4. mm/mmap.c
// 在函数 do_mmap() 上面添加
// 具体的实现
static pte_t*
addr_to_pte(struct mm_struct *mm, unsigned long addr)
{
	return pte_offset_kernel(pmd_off(mm, addr), addr);
}

SYSCALL_DEFINE3(peep_page, pid_t, tar_pid_nr, unsigned long, tar_addr, unsigned long, my_addr)
{
	printk("peep_page: running!\n");

	// 学生TODO: 请添加代码

	return 0;
}
