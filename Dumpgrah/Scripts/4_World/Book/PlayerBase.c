modded class PlayerBase
{
	protected bool	m_BookMenuToggle;

	void ToggleBookReading()
	{
		m_BookMenuToggle = !m_BookMenuToggle;
	}
	bool IsReadingBook()
	{
		return m_BookMenuToggle;
	}
}