int main()
{
	char *str = "yo dude";
	printf("the address is : %p\n", str);
	printf("%c\n", *(str));
	printf("the address is : %p\n", str + 1);
	printf("%c\n", *(str + 1));
	printf("the address is : %p\n", str + 2);
	printf("%c\n", *(str + 2));
}