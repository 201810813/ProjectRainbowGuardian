#pragma once
class PathManager
{
private:
	static shared_ptr<PathManager>	Instance;

	PathManager() = default;
	PathManager(const PathManager& other) = delete;

	~PathManager()
	{

	}

	PathManager& operator = (const PathManager& other) = delete;

	static void Destroy(PathManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<PathManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<PathManager>(new PathManager(), Destroy);
		}

		return Instance;
	}

private:
	wchar_t		m_szContentPath[256];

public:
	void Initialize();

	const wchar_t* GetContentPath() { return m_szContentPath; }
};

