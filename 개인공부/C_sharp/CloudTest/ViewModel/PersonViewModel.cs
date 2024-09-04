using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using CloudTest.Model;

namespace CloudTest.ViewModel
{
    public class PersonViewModel : INotifyPropertyChanged
    {
        private Person _person;

        public PersonViewModel()
        {
            _person = new Person { Name = "John Doe",Age =30};
        }
        public string Name
        {
            get=>_person.Name;
            set
            {
                if (_person.Name != value)
                {
                    _person.Name = value;
                    OnPropertyChanged();
                }
            }
        }

        public int Age
        {
            get => _person.Age;
            set
            {
                if (_person.Age != value)
                {
                    _person.Age = value;
                    OnPropertyChanged();
                }
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
