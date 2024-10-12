
#include "../inc/tokens.h"

static void	get_s(t_mini *m, t_sort *s)
{
	int		i;
	t_token	*now;

	s->a_now = m->t_head->next;
	now = m->t_head->next;
	i = 0;
	while (i++ < m->a_size)
		now = now->next;
	s->b_now = now;
	s->idx_a = 0;
	s->idx_b = 0;
}

static void	merge(t_mini *m, t_sort *s)
{
	if (s->a_now->pos > s->b_now->pos)
	{
		s->idx_b++;
		m->t_tail->next = s->b_now;
		s->b_now = s->b_now->next;
	}
	else
	{
		s->idx_a++;
		m->t_tail->next = s->a_now;
		s->a_now = s->a_now->next;
	}
	m->t_tail = m->t_tail->next;
}

void	sort(t_mini *m)
{
	t_sort	s;

	get_s(m, &s);
	m->t_tail = m->t_head;
	while (s.idx_a < m->a_size && s.idx_b < m->b_size)
		merge(m, &s);
	if (s.idx_a == m->a_size)
	{
		m->t_tail->next = s.b_now;
		while (s.idx_b++ < m->b_size)
			m->t_tail = m->t_tail->next;
	}
	else
	{
		m->t_tail->next = s.a_now;
		while (s.idx_a++ < m->a_size)
			m->t_tail = m->t_tail->next;
	}
	m->t_tail->next = NULL;
	m->a_size += m->b_size;
	m->b_size = 0;
}
