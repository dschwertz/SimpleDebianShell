long ish_read(
        int file_descriptor,
        void *buffer,
        unsigned long buffer_size
     )
{
	long result; 

	__asm__ __volatile__ (
		"mov $0, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(file_descriptor), "S"(buffer), "d"(buffer_size)
	);

    return result;
}

int ish_chdir(const char *path)
{
	long result;

    	__asm__ __volatile__ (
		"mov $80, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(path)
	);

    return result;
}

void ish_exit(int status)
{
    long result;

    	__asm__ __volatile__ (
		"mov $60, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(status)
	);

}

int ish_stat(const char *path, void *stat_result)
{

    long result;

    	__asm__ __volatile__ (
		"mov $4, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(path), "S"(stat_result)
	);

    return result;
}

int ish_open(const char *path, int flags)
{
    long result;

    	__asm__ __volatile__ (
		"mov $2, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(path), "S"(flags)
	);

    return result;
}

int ish_creat(const char *path, unsigned int mode)
{
    long result;

    	__asm__ __volatile__ (
		"mov $85, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(path), "S"(mode)
	);

    return result;
}

int ish_dup2(int old_file_descriptor, int new_file_descriptor)
{
    long result;

    	__asm__ __volatile__ (
		"mov $33, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(old_file_descriptor), "S"(new_file_descriptor)
	);

    return result;
}

int ish_close(int file_descriptor)
{
    long result;

    	__asm__ __volatile__ (
		"mov $3, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(file_descriptor)
	);

    return result;
}

int ish_fork()
{
    long result;

    	__asm__ __volatile__ (
		"mov $57, %%rax;"
		"syscall;"
		:"=a"(result)	
	);

    return result;
}

int ish_execve(
        const char *path,
        char *const arguments[],
        char *const environment[]
    )
{
    long result;

    	__asm__ __volatile__ (
		"mov $59, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(path), "S"(arguments), "d"(environment)
	);

    return result;
}

int ish_waitpid(int pid, int *status, int options)
{

    long result;

    	__asm__ __volatile__ (
		"mov $61, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(pid), "S"(status), "d"(options)
	);

    return result;
}

long ish_write(
        int file_descriptor,
        const void *buffer,
        unsigned long buffer_size
     )
{
    long result;

    	__asm__ __volatile__ (
		"mov $1, %%rax;"
		"syscall;"
		:"=a"(result)
		:"D"(file_descriptor), "S"(buffer), "d"(buffer_size)
	);

    return result;
}
