char *Brute_Force(char *source, char *substr, int *k)
  {
     int  i = 0, j = 0, m, n;
     n = strlen(source) - 1;
     m = strlen(substr) - 1;
     do {
       if (source == substr[j])
       {
         i++;
         j++;
       }
       else
       {
          i = i - j + 2;
          j = 0;
       }
     } while (j <= m && i <= n);
     if (j > m)
     {
       *k = i - m - 1;
       return source + i - m - 1;
     }
     else
       return NULL;
  }

  int KMP(char *source, char *find)
  {
    int next[MAX], i = 0, len, j=-1, lensource;
   
    len = strlen(find);
    lensource = strlen(source);
    next[0] = -1;
    do {
      if (j == -1 || find[i] == find[j])
      {
        i++;
        j++;
        next[i] = j;
      }
      else
        j = next[j];
    } while (i < len-1);
    i = j = 0;
    do {
      if (j==0 || source[i] == find[j])
      {
        i++;
        j++;
      }
      else
        j = next[j];
    } while (j<len && i<lensource);
    if (j>=len)
      return i-len;
    else
      return -1;
  }

  int BoyerMoore(char *source, char *find)
{
  int skip[MAX], i = 0, len, j=-1, lensource;
 
  len = strlen(find);
  lensource = strlen(source);
  for (i=0; i<MAX; i++)
    skip[i] = len-1;
  for (i=0; i<len; i++)
    if (skip[find[i]] == len-1)
       skip[find[i]] = len-i-1;
 
  i = j = len-1;
  do {
    if (source[i] == find[j])
    {
      i--;
      j--;
    }
    else
    {
      if (len-j+1 > skip[source[i]])
        i += len-j+1;
      else
        i += skip[source[i]];
      j = len-1;
    }
  } while (j>0 && i<lensource);
 
  if (j<=0)
    return i;
  else
    return -1;
}
