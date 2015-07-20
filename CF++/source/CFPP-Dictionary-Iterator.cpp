/*******************************************************************************
 * Copyright (c) 2014, Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        CFPP-Dictionary-Iterator.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Iterator class for CF::Dictionary
 */

#include <CF++.hpp>

namespace CF
{
    Dictionary::Iterator::Iterator( void ):
        _cfObject( NULL ),
        _keys( static_cast< CFArrayRef >( NULL ) ),
        _count( 0 ),
        _pos( 0 )
    {}
    
    Dictionary::Iterator::Iterator( const Iterator & value ):
        _cfObject( value._cfObject ),
        _keys( value._keys ),
        _count( value._count ),
        _pos( value._pos )
    {
        if( this->_cfObject != NULL )
        {
            CFRetain( this->_cfObject );
        }
    }
    
    Dictionary::Iterator::Iterator( CFDictionaryRef dictionary, CFIndex count, CFIndex pos ):
        _cfObject( dictionary ),
        _count( count ),
        _pos( pos )
    {
        CFTypeRef * cfKeys;
        CFIndex     i;
        
        if( this->_cfObject == NULL )
        {
            return;
        }
        
        CFRetain( this->_cfObject );
        
        if( count == 0 )
        {
            return;
        }
        
        cfKeys = new CFTypeRef[ static_cast< size_t >( count ) ];
        
        if( cfKeys == NULL )
        {
            return;
        }
        
        memset( cfKeys, 0, static_cast< size_t >( count ) );
        
        CFDictionaryGetKeysAndValues( this->_cfObject, reinterpret_cast< const void ** >( cfKeys ), NULL );
        
        for( i = 0; i < count; i++ )
        {
            _keys << cfKeys[ i ];
        }
        
        delete [] cfKeys;
    }
    
    #ifdef CFPP_HAS_CPP11
    Dictionary::Iterator::Iterator( Iterator && value )
    {
        this->_cfObject = value._cfObject;
        value._cfObject = NULL;
        this->_count    = value._count;
        value._count    = 0;
        this->_pos      = value._pos;
        value._pos      = 0;
        
        swap( this->_keys, value._keys );
    }
    #endif
    
    Dictionary::Iterator::~Iterator( void )
    {
        if( this->_cfObject != NULL )
        {
            CFRelease( this->_cfObject );
        }
    }
    
    Dictionary::Iterator & Dictionary::Iterator::operator = ( Iterator value )
    {
        swap( *( this ), value );
        
        return *( this );
    }
    
    Dictionary::Iterator & Dictionary::Iterator::operator ++( void )
    {
        this->_pos++;
        
        return *( this );
    }
    
    Dictionary::Iterator Dictionary::Iterator::operator ++( int )
    {
        Iterator it( *( this ) );
        
        operator++();
        
        return it;
    }
    
    Dictionary::Iterator & Dictionary::Iterator::operator --( void )
    {
        this->_pos--;
        
        return *( this );
    }
    
    Dictionary::Iterator Dictionary::Iterator::operator --( int )
    {
        Iterator it( *( this ) );
        
        operator--();
        
        return it;
    }
    
    Dictionary::Iterator & Dictionary::Iterator::operator += ( CFIndex value )
    {
        this->_pos += value;
        
        return *( this );
    }
    
    Dictionary::Iterator & Dictionary::Iterator::operator -= ( CFIndex value )
    {
        this->_pos -= value;
        
        return *( this );
    }
    
    Dictionary::Iterator Dictionary::Iterator::operator + ( CFIndex value )
    {
        Iterator i;
        
        i = *( this );
        
        return i += value;
    }
    
    Dictionary::Iterator Dictionary::Iterator::operator - ( CFIndex value )
    {
        Iterator i;
        
        i = *( this );
        
        return i -= value;
    }
    
    bool Dictionary::Iterator::operator == ( const Iterator & value ) const
    {
        if( this->_cfObject != value._cfObject )
        {
            return false;
        }
        
        if( this->_count != value._count )
        {
            return false;
        }
        
        if( this->_pos != value._pos )
        {
            return false;
        }
        
        return true;
    }
    
    bool Dictionary::Iterator::operator != ( const Iterator & value ) const
    {
        return !( *( this ) == value );
    }
    
    CF::Pair Dictionary::Iterator::operator * ( void ) const
    {
        return CF::Pair( this->GetKey(), this->GetValue() );
    }
    
    CFTypeRef Dictionary::Iterator::GetKey( void ) const
    {
        if( this->_cfObject == NULL )
        {
            return NULL;
        }
        
        if( this->_count == 0 )
        {
            return NULL;
        }
        
        if( this->_pos >= this->_count )
        {
            return NULL;
        }
        
        if( this->_pos < 0 )
        {
            return NULL;
        }
        
        return this->_keys.GetValueAtIndex( this->_pos );
    }
    
    CFTypeRef Dictionary::Iterator::GetValue( void ) const
    {
        CFTypeRef key;
        
        key = this->GetKey();
        
        if( key == NULL )
        {
            return NULL;
        }
        
        return CFDictionaryGetValue( this->_cfObject, key );
    }
    
    void swap( Dictionary::Iterator::Iterator & v1, Dictionary::Iterator::Iterator & v2 )
    {
        using std::swap;
        
        swap( v1._cfObject, v2._cfObject );
        swap( v1._keys,     v2._keys );
        swap( v1._count,    v2._count );
        swap( v1._pos,      v2._pos );
    }
}
