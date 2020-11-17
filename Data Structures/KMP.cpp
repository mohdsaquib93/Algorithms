#include <iostream>

using namespace std;

int *preprocess(string pat)
{
	int *lps = new int[pat.size()];
	int i = 1;
	int j = 0;
	lps[j] = 0;

	while (i < pat.size()) {
		if (pat.at(i) == pat.at(j)) {
			++j;
			lps[i++] = j;
		}
		else {
			if (j)
				j = lps[j - 1];
			else
				lps[i++] = 0;
		}
	}

	return lps;
}

void KMP(string txt, string pat)
{
	int *lps = preprocess(pat);
	int i = 0, j = 0;

	while (i < txt.size()) {
		if (txt.at(i) == pat.at(j)) {
			++i;
			++j;
		}
		
		if (j == pat.size()) {
			cout << "Pattern found at location " << i - j << endl;
			j = lps[j - 1];
		}

		if (i < txt.size() && txt.at(i) != pat.at(j)) {
			if (j)
				j = lps[j - 1];
			else
				++i;
		}
	}
}

int main()
{
	string txt = "goodgogogooglegooglegogoogle";
	string pat = "gogoogle";

	KMP(txt, pat);

	return 0;
}
