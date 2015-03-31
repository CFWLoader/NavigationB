#ifndef _NAVIGATIONMAP_H_
#define _NAVIGATIONMAP_H_

#include "Stdafx.h"
#include "BaseStructure.h"

// ������
class NavigationGraph
{
private:
	std::deque<Navigation_Point*> Points;
public:
	NavigationGraph()
	{
	}

	// ����:
	// �����µ�·��
	// ����:
	// x, y, z--·�������, type--·�������, _name--·�������
	// ·�����Ͳμ�PointType, ��BaseStructure.h��
	void AddNewPoint(double x, double y, double z, int type, std::string _name);

	// ����:
	// ��������·��
	// ����:
	// pFrom--��·��, pTo--��·��
	void AddNewEdge(Navigation_Point *pFrom, Navigation_Point *pTo);

	// ����:
	// ��������·��
	// ����:
	// FromName--��·������, ToName--��·������
	void AddNewEdge(std::string &FromName, std::string &ToName);

	// ����:
	// ��������·��
	// ����:
	// FromName--��·������, ToName--��·������
	// ����char*д��
	void AddNewEdge(char *FromName, char *ToName);

	// ����:
	// ͨ�����ƻ�ȡ·��
	// ����:
	// name--·������
	// ����ֵ:
	// ·��ָ��
	Navigation_Point *GetPointByName(std::string &name);

	// ����:
	// �������·���Լ������ӱ�
	void DebugPrint();
};

// ��B¥
class Building_B
{
private:
	NavigationGraph TheGraph;

	void GenerateGraph();
public:
	Building_B(){GenerateGraph();}

	// ����:
	// ��ȡ·��
	// ����ֵ:
	// ·��������
	NavigationGraph &GetGraph(){return TheGraph;}

	// ����:
	// ���·��������·���Լ������ӱ�
	void DebugPrint(){TheGraph.DebugPrint();}
};
#endif