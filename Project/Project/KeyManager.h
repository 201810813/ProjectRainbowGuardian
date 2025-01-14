#pragma once

class KeyManager
{
private:
	static	shared_ptr<KeyManager>	Instance;
	vector<Key_Info>				m_KeyInfo;
	
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

	KEY_STATE GetKeyState(KEY_TYPE _key)
	{
		return m_KeyInfo[(UINT)_key]._KState;
	}

	void Initialize();
	void tick();
};

