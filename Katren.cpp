#include "Katren.h"

bool Katren::operator*() const
{
	if ((this->tail->data ^ this->head->data) && (this->head->next->data ^ this->head->next->next->data) && this->pom == 0) return true;
	else return false;
}

char Katren::oznaka() const
{
	return 'K';
}