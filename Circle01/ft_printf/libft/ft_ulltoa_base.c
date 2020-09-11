/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:47:49 by gipark            #+#    #+#             */
/*   Updated: 2020/09/12 02:05:59 by gipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_ulltoa_base(unsigned long long int n, char *base)
{
	char					str;
	unsigned long long int	nbr;
	size_t					size;
	int						base_len;

	base_len = ft_strlen(base);
	nbr = n;
	size = 1;
	while (n /= base_len)
		size++;
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (size == 0 && str[1] == '\0')
		str[0] = '0';
	return (str);
}
