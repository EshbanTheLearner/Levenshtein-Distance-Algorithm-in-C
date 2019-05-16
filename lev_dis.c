#include <stdio.h>
#include <string.h>

int levenshtein(const char *s, int ls, const char *t, int lt){
	
	int a, b, c;

	// If either string is empty
	// 		difference is inserting all chars from the other

	if(!ls) return lt;
	if(!lt) return ls;

	// If last letters are same
	// 		the difference is whatever is required to edit the rest of the strings

	if(s[ls-1] == t[lt-1])
		return levenshtein(s, ls-1, t, lt-1);

	// Else try:
	// 		changing last letter of s to that of t; or
	// 		remove last letter of s; or
	// 		remove last letter of t;
	// any of which is 1 edit plus editing the rest of the strings

	a = levenshtein(s, ls-1, t, lt-1);
	b = levenshtein(s, ls, t, lt-1);
	c = levenshtein(s, ls-1, t, lt);

	if(a>b) a=b;
	if(a>c) a=c;

	return a+1;
}

int main(){

	const char *s1 = "eshban";
	const  char *s2 = "eshan";
	printf("Distance beteen '%s' and '%s': %d\n", s1, s2, levenshtein(s1, strlen(s1), s2, strlen(s2)));

	const char *str1 = "brooklyn";
	const char *str2 = "atlanta";
	printf("Distance beteen '%s' and '%s': %d\n", str1, str2, levenshtein(str1, strlen(str1), str2, strlen(str2)));

	return 0;
}
