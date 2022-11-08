#include "InternalCombustionEngine.h"

InternalCombustionEngine::InternalCombustionEngine(int Tenv) 
{
	TEng = Tenv;
}

InternalCombustionEngine::~InternalCombustionEngine()
{
}

void InternalCombustionEngine::EngineStart()
{
	setWorking(true);
	Working();
}

double InternalCombustionEngine::getTimeHasWorked()
{
	return workedTime;
}

void InternalCombustionEngine::Working()
{
	double dt = 0.001, V_AatTheMoment = 0.0; //dt - ����� ���������� �������
	int current = 0, s = V.size(); // ���������� ����� �������� �������� M � V
	workedTime = 0;
	Tenv = TEng;
	while (IsWorking()) { //��������� ������� ������� ������� ������
		double a = M[current] / I; // ���������� ���������
		V_AatTheMoment = V_AatTheMoment + (a * dt);
		Vh = (M[current] * Hm) + (V_AatTheMoment * V_AatTheMoment * Hv);
		Vc = C * (Tenv - TEng);
		
		TEng = TEng + ( (C * (Vh + Vc)) * dt); // ����������� ��������� - �������� ������� �������� + ��������� �� ����� ����
		
		if (current < s - 1)
		{
			if (V_AatTheMoment >= V[current + 1] && current < s - 1)
				++current;
		}

		if (TEng < TOverhating) // ��������������� ������� �������, ���� ����������� ��������� > ����������� ���������
		{ 
			workedTime += dt;
		}
	}
}

void InternalCombustionEngine::EngineStop()
{
	setWorking (false);
}

bool InternalCombustionEngine::IsWorking()
{
	return working;
}

void InternalCombustionEngine::setWorking(bool condition)
{
	working = condition;
}

double InternalCombustionEngine::getEngineTemperature()
{
	return TEng;
}

double InternalCombustionEngine::getOverhatingTemperature()
{
	return TOverhating;
}


