#pragma once

class KeyManager
{
private:
	static	shared_ptr<KeyManager>	Instance;
	//vector<Key_Info>				m_KeyInfo;
	
	KeyManager() = default;
	KeyManager(const KeyManager& other) = delete;

	~KeyManager() {}

	KeyManager& operator = (const KeyManager& other) = delete;

	static void Destroy(KeyManager* InstancePtr)
	{
		delete InstancePtr;
	}

public:
	static shared_ptr<KeyManager> GetInstance()
	{
		if (nullptr == Instance)
		{
			Instance = shared_ptr<KeyManager>(new KeyManager(), Destroy);
		}

		return Instance;
	}

	void Initialize();
	void tick();
};

