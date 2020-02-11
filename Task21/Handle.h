#pragma once

template <typename Traits>
class Handle
{
private:
	using pointer = typename Traits::pointer;
	pointer m_value;

public:
	Handle(Handle const&) = delete;
	Handle& operator=(Handle const&) = delete;

	explicit Handle(pointer value = Traits::invalid()) noexcept
		: m_value(value) {}

	Handle(Handle&& other) noexcept
		: m_value(other.release()) {}

	Handle& operator=(Handle&& other) noexcept
	{
		if (this != &other)
			reset(other.release());

		return *this;
	}

	~Handle() noexcept { Traits::close(m_value); }

	explicit operator bool() const noexcept { return m_value != Traits::invalid(); }

	pointer get() const noexcept { return m_value; }

	pointer release() noexcept
	{
		auto value = m_value;
		m_value = Traits::invalid();
		return value;
	}

	bool reset(pointer value = Traits::invalid()) noexcept
	{
		if (m_value != value)
		{
			Traits::close(m_value);
			m_value = value;
		}

		return static_cast<bool>(*this);
	}

	void swap(Handle<Traits>& other) noexcept { std::swap(m_value, other.operator bool); }
};