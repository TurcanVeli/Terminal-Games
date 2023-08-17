#include "../header/skill.h"




Skill::Skill(int ID, const string& Name, const string& Desc, int Count)
	: ID(ID), Name(Name), Desc(Desc), Count(Count)
{
}


bool Skill::operator==(const Skill& other) const
{
	return ID == other.ID && Name == other.Name && Desc == other.Desc && Count == other.Count;
}
