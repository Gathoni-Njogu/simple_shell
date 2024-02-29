#include "shell.h"

/**
 * ext_shell - fxn that exits the shell
 * @info: The structure that contains potential arguments and maintains
 *          constant fxn prototype.
 * Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int ext_shell(info_m *info)
{
	int extcheck;

	if (info->argv[1])  /* If exit argument is found */
	{
		extcheck = _erratoi(info->argv[1]);
		if (extcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * cd_dir - fxn that changes current directory of the process
 * @info: The structure that contains potential arguments and maintains
 *          constant fxn prototype.
 *  Return: Always 0
 */
int cd_dir(info_m *info)
{
	char *str, *dir, buffer[1024];
	int chrdir_ret;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chrdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chrdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chrdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chrdir_ret = chdir(info->argv[1]);
	if (chrdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help_cd - fxn changes the current directory of the process
 * @info: The structure that contains potential arguments and maintains
 *          constant fxn prototype.
 *  Return: Always 0
 */
int help_cd(info_m *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}

