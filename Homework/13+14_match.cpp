int Match(char *pattern, char *str)
{
  int i;
  int j;
  for (i=0, j=0;( i<strlen(pattern) ) && ( j <strlen(str)) ;i++,j++)
  {
    if ( pattern[i] == '?')
      continue;
    else if (pattern[i] != str[j])
      return 0;
  }
  if ( (i==strlen(pattern)) && (j == strlen(str)) )
    return 1;
  else
    return 0;
}

int Match(char *pattern, char *str)
{
  int i;
  int j;
  for (i=0, j=0;( i<strlen(pattern) ) && ( j <strlen(str)) ;i++,j++)
  {
    if ( pattern[i] == '?')
      continue;
    else if (pattern[i] == '*')
    {
      if (i==strlen(pattern)-1) return 1;
      else if (Match(&pattern[i+1], &str[i])) return 1;
      else if (Match(&pattern[i], &str[j+1])) return 1;
      else return 0;
    }
    else if (pattern[i] != str[j])
    return 0;
  }
  if ( (i==strlen(pattern)) && (j == strlen(str)) )
    return 1;
  else
    return 0;
}