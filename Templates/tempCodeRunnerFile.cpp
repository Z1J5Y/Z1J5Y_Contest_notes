void Euler()
{
	for (ll i = 2; i <= b; ++i)
	{
		if (!flag[i])
			primes.push_back(i);
		for (ll j = 0; j < primes.size() && i * primes[j] < b; ++j)
		{
			flag[i * primes[j]] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
}