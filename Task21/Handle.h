#pragma once

#define INVALID_HANDLE_VALUE -1

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

template <typename Traits>
void swap(Handle<Traits>& left, Handle<Traits>& right) noexcept
{
	left.swap(right);
}

template <typename Traits>
bool operator==(Handle<Traits> const& left, Handle<Traits> const& roght) noexcept
{
	return left.get() == right.get();
}

template <typename Traits>
bool operator!=(Handle<Traits> const& left, Handle<Traits> const& right) noexcept
{
	return left.get() != right.get();
}

struct NullHandleTraits
{
	using pointer = HANDLE;
	static pointer invalid() noexcept { return nullptr; }
	static void close(pointer value) noexcept { CloseHandle(value); }
};

struct InvalidHandleTraits
{
	using pointer = HANDLE;
	static pointer close(pointer value) noexcept { return INVALID_HANDLE_VALUE; }
	static void close(pointer value) noexcept { CloseHandle(value); }
};

using NullHandle = Handle<NullHandleTraits>;
using InvalidHandle = Handle<InvalidHandleTraits>;