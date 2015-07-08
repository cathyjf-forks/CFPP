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
 * @file        CFPP-ReadStream-Iterator.cpp
 * @copyright   (c) 2014 - Jean-David Gadina - www.xs-labs.com / www.digidna.net
 * @abstract    Iterator class for CF::ReadStream
 */

#include <CF++.hpp>

namespace CF
{
    ReadStream::Iterator::Iterator( void )
    {}
    
    ReadStream::Iterator::Iterator( CFReadStreamRef stream, CFIndex bytesToRead )
    {
        ( void )stream;
        ( void )bytesToRead;
    }
    
    ReadStream::Iterator::Iterator( const Iterator & value )
    {
        ( void )value;
    }

    #ifdef CFPP_HAS_CPP11
    ReadStream::Iterator::Iterator( Iterator && value )
    {
        ( void )value;
    }
    #endif

    ReadStream::Iterator::~Iterator( void )
    {}

    ReadStream::Iterator & ReadStream::Iterator::operator = ( Iterator value )
    {
        ( void )value;
        
        return *( this );
    }
    
    ReadStream::Iterator & ReadStream::Iterator::operator ++( void )
    {
        return *( this );
    }
    
    ReadStream::Iterator ReadStream::Iterator::operator ++( int )
    {
        return *( this );
    }
    
    ReadStream::Iterator & ReadStream::Iterator::operator --( void )
    {
        return *( this );
    }
    
    ReadStream::Iterator ReadStream::Iterator::operator --( int )
    {
        return *( this );
    }

    ReadStream::Iterator & ReadStream::Iterator::operator += ( CFIndex value )
    {
        ( void )value;
        
        return *( this );
    }
    
    ReadStream::Iterator & ReadStream::Iterator::operator -= ( CFIndex value )
    {
        ( void )value;
        
        return *( this );
    }

    ReadStream::Iterator ReadStream::Iterator::operator + ( CFIndex value )
    {
        ( void )value;
        
        return *( this );
    }
    
    ReadStream::Iterator ReadStream::Iterator::operator - ( CFIndex value )
    {
        ( void )value;
        
        return *( this );
    }

    bool ReadStream::Iterator::operator == ( const Iterator & value ) const
    {
        ( void )value;
        
        return false;
    }
    
    bool ReadStream::Iterator::operator != ( const Iterator & value ) const
    {
        ( void )value;
        
        return false;
    }

    Data ReadStream::Iterator::operator * ( void ) const
    {
        return static_cast< CFDataRef >( NULL );
    }
    
    Data ReadStream::Iterator::operator -> ( void ) const
    {
        return static_cast< CFDataRef >( NULL );
    }

    ReadStream::Iterator::operator Data () const
    {
        return static_cast< CFDataRef >( NULL );
    }

    void swap( ReadStream::Iterator & v1, ReadStream::Iterator & v2 )
    {
        ( void )v1;
        ( void )v2;
    }
}